uses math;

const maxn = 201010;
const dx: array [0..3] of longint = (-1, 0, 1, 0);
const dy: array [0..3] of longint = (0, -1, 0, 1);
function getdir(c: char): byte;
begin
  if c = 'L' then exit(0);
  if c = 'D' then exit(1);
  if c = 'R' then exit(2);
  // if c = 'U' then exit(3);
  exit(3);
end;

var
  n: longint;
  s: ansistring;
  ex, ey: longint;
  preposx, preposy: array[0..maxn] of longint;
  posposx, posposy: array[0..maxn] of longint;

procedure preprocess;
var i, d: longint;
begin
  preposx[0] := 0;
  preposy[0] := 0;
  for i := 1 to n do begin
    d := getdir(s[i]);
    preposx[i] := preposx[i - 1] + dx[d];
    preposy[i] := preposy[i - 1] + dy[d];
  end;

  posposx[n + 1] := ex;
  posposy[n + 1] := ey;
  for i := n downto 1 do begin
    d := getdir(s[i]);
    posposx[i] := posposx[i + 1] - dx[d];
    posposy[i] := posposy[i + 1] - dy[d];
  end;
end;

function ok(len: longint): boolean;
var
  i: longint;
  dx, dy, d: longint;
begin
  for i := 1 to n - len + 1 do begin
    dx := preposx[i - 1] - posposx[i + len];
    dy := preposy[i - 1] - posposy[i + len];
    d := abs(dx) + abs(dy);
    if (len + d) mod 2 = 1 then continue;
    if len >= d then exit(true);
  end;
  exit(false);
end;

var
  l, r, mid: longint;

begin
  readln(n);
  readln(s);
  readln(ex, ey);
  preprocess;
  l := 0;
  r := n + 1;
  while l < r do begin
    mid := l + (r - l) div 2;
    if ok(mid) then r := mid
    else l := mid + 1;
  end;
  if l = n + 1 then writeln(-1)
  else writeln(l);
end.