uses math;
var
  n: longint;
  x: longint;
  i: longint;
  c0, c5: longint;

begin
  read(n);
  c0 := 0; c5 := 0;
  for i := 1 to n do begin
    read(x);
    if x = 0 then inc(c0)
    else inc(c5);
  end;
  c5 := c5 div 9 * 9;
  if c0 = 0 then writeln(-1)
  else if c5 = 0 then writeln(0)
  else begin
    for i := 1 to c5 do write(5);
    for i := 1 to c0 do write(0);
  end;
end.