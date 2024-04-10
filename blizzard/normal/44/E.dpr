{$Apptype console}
uses
  SysUtils;
type
t = array[0..10000] of longint;
var k, a, b, r, diff, n, i, cur, j : longint;
    s : string;
    c : t;
begin
 { assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output);}
  readln(k, a, b);
  readln(s);
  n := length(s);
  if (k * b < n) or (k * a > n) then begin
    write('No solution');
    halt(0);
  end;
  for i := 1 to k do
    c[i] := a;

  diff := n - k * a;
  r := b - a;
  for i := 1 to k do
    if diff <= r then begin
      c[i] := c[i] + diff;
      break;
    end
    else begin
      diff := diff - r;
      c[i] := c[i] + r;
    end;
  cur := 0;
  for i := 1 to k do begin
    for j := 1 to c[i] do
      write(s[cur + j]);
    writeln;
    cur := cur + c[i];
  end;
end.