{$Apptype console}
uses
  SysUtils;
type
t2 = array[0..5050] of extended;
t1 = array[0..5050] of t2;
var d : t1;
    x, y, z : t2;
    n, i, j : longint;
    min : extended;
begin
  {assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output); }
  read(n);
  for i := 1 to n do
    read(x[i], y[i], z[i]);
  for i := 1 to n do
    for j := 1 to n do begin
      d[i, j] := sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
    end;
  min := 1000000000000000000;
  for i := 2 to n do
    for j := i + 1 to n do
      if d[1, i] + d[1, j] + d[i, j] < min then min := d[1, i] + d[1, j] + d[i, j];
  write((min / 2) : 0 : 8);
end.