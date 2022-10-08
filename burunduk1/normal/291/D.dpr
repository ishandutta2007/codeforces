const 
  maxN = 10000;
type
  int = longint;
var
  x, j, i, n, k : int;
  a : array[1..maxN] of int;
  b : array[1..maxN] of int;
begin
  read(n, k);
  for i := 1 to n - 1 do
    a[i] := 1;
  for i := 1 to k do begin
    x := 1;
    for j := 1 to n do begin
      while a[j] + a[x] > n - j do
        inc(x);
      write(x, ' ');
      b[j] := a[x];
    end;
    writeln;
    for j := 1 to n do 
      inc(a[j], b[j]);
  end
end.