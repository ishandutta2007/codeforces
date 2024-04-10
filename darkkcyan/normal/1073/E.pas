uses math;

{$OPTIMIZATION LEVEL2}
{$Q-}
const ord0 = ord('0');
const maxlen = 20;
const rem: int64 = 998244353;
var
  l, r: int64;
  k: byte;

var bitcount: array[0..(1 shl 10)] of int64;
var p10: array[0..maxlen] of int64;
procedure preprocess;
var
  i: longint;
begin
  bitcount[0] := 0;
  for i := 1 to (1 shl 10) - 1 do begin
    bitcount[i] := bitcount[i div 2] + i mod 2;
  end;
  p10[0] := 1;
  for i := 1 to maxlen do begin
    p10[i] := (p10[i - 1] * 10) mod rem;
  end;
end;

function torevstring(num: int64): string;
var
  ans: string;
begin
  if num = 0 then exit('0');
  ans := '';
  while num > 0 do begin
    ans := ans + char(ord0 + num mod 10);
    num := num div 10;
  end;
  exit(ans);
end;

var 
  dp, cnt: array[0..maxlen, 0..(1 shl 10), false..true] of int64;
  curs: string;

procedure cal(pos: longint; digmask: longint; bound: boolean);
var
  i: longint;
  lastdig: byte;
  newmask : longint;
  newbound: boolean;
  tcnt, ans: int64;
begin
  if pos = 0 then begin
    dp[pos][digmask][bound] := 0;
    cnt[pos][digmask][bound] := 1;
    exit;
  end;
  if dp[pos][digmask][bound] <> -1 then
    exit;
  lastdig := 9;
  if bound then lastdig := ord(curs[pos]) - ord0;
  ans := 0;
  for i := 0 to lastdig do begin
    newmask := digmask;
    if (digmask <> 0) or (i <> 0) then 
      newmask := digmask or (1 shl i);
    if bitcount[newmask] > k then continue;

    newbound := false;
    if bound then newbound := i = lastdig;
    cal(pos - 1, newmask, newbound);
    tcnt := cnt[pos - 1][newmask][newbound];

    inc(cnt[pos][digmask][bound], tcnt);
    cnt[pos][digmask][bound] := cnt[pos][digmask][bound] mod rem;

    inc(ans, dp[pos - 1][newmask][newbound]);
    ans := ans mod rem;

    inc(ans, (i * p10[pos - 1] mod rem) * tcnt mod rem);
    ans := ans mod rem;
  end;
  dp[pos][digmask][bound] := ans;
  //writeln(stderr, pos, ' ', digmask, ' ', bound, ' ', dp[pos][digmask][bound], ' ', cnt[pos][digmask][bound]);
end;

var
  ans: int64;
begin
  preprocess;
  read(l, r, k);
  fillchar(dp, sizeof(dp), 255);
  fillchar(cnt, sizeof(cnt), 0);
  curs := torevstring(r);
  cal(length(curs), 0, true);
  ans := dp[length(curs)][0][true];
  //writeln(stderr);
  if l <> 0 then begin
    fillchar(dp, sizeof(dp), 255);
    fillchar(cnt, sizeof(cnt), 0);
    curs := torevstring(l - 1);
    cal(length(curs), 0, true);
    dec(ans, dp[length(curs)][0][true]);
    ans := ans mod rem;
    if ans < 0 then inc(ans, rem);
  end;
  writeln(ans);
end.