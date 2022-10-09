{$mode objfpc}
uses math;
const maxn = 8;

procedure swap(var a, b: longint);
var t: longint; begin t := a; a := b; b := t; end;

function nextpre(var a: array of longint): boolean;
var i, f, g: longint;
begin
  for i := high(a) - 1 downto low(a) do
    if a[i] < a[i + 1] then break;
  if a[i] >= a[i + 1] then exit(false);
  f := i + 1; g := high(a);
  while f < g do begin
    swap(a[f], a[g]);
    inc(f); 
    dec(g);
  end;
  for f := i + 1 to high(a) do
    if a[f] > a[i] then break;
  swap(a[i], a[f]);
  exit(true);
end;


function tonum(const s: string; order: array of longint): longint;
var i: longint;
begin
  result := 0;
  for i := 1 to length(s) do begin
    result := result * 10 + (ord(s[order[i]]) - ord('0'));
  end;
end;

var
  n, k: longint;
  a: array[0..maxn] of string;
  b: array[0..maxn] of longint;
  i, mi, ma, t: longint;
  ans: longint;

begin
  readln(n, k);
  for i := 1 to n do readln(a[i]);
  for i := 1 to k do b[i] := i;
  ans := 999999999;
  repeat
    mi := 999999999;
    ma := -1;
    for i := 1 to n do begin
      t := tonum(a[i], b);
      mi := min(mi, t);
      ma := max(ma, t);
    end;
    ans := min(ans, ma - mi);
  until not nextpre(b[1..k]);
  writeln(ans);
end.