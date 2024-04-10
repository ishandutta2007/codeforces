uses math;

var
  n: longint;
  s: ansistring;

function mindis(u: char; v: char): longint;
var t: longint;
begin
  t := abs(ord(u) - ord(v));
  exit(min(t, 26 - t));
end;

var
  ans: longint;
  i: longint;

begin
  readln(n);
  readln(s);
  ans := 1000000;
  for i := 1 to n - 3 do begin
    ans := min(ans, mindis(s[i], 'A') + mindis(s[i + 1], 'C') + mindis(s[i + 2], 'T') + mindis(s[i + 3], 'G'));
  end;
  writeln(ans);
end.