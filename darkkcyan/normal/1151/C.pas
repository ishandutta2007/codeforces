uses math;

const rem: int64 = 1000 * 1000 * 1000 + 7;

function cal_even(n: int64): int64;
begin
  n := n mod rem;
  exit(n * (n + 1) mod rem);
end;

function cal_odd(n: int64): int64;
var ans: int64;
begin
  ans := (cal_even(n) - n mod rem) mod rem;
  if ans < 0 then inc(ans, rem);
  exit(ans);
end;

function cal(n: int64): int64;
var
  cnt: array[false..true] of int64;
  i, t: int64;
  s: boolean = true;
begin
  i := 1;
  cnt[false] := 0; cnt[true] := 0;
  while n > 0 do begin
    t := min(n, i);
    dec(n, t);
    inc(cnt[s], t);
    s := not s;
    i := i * 2;
  end;
  exit((cal_even(cnt[false]) + cal_odd(cnt[true])) mod rem);
end;

var l, r: int64;
var ans: int64;
begin
  read(l, r);
  ans := (cal(r) - cal(l - 1)) mod rem;
  if ans < 0 then inc(ans, rem);
  writeln(ans);
end.