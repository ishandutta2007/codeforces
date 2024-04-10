var n, m, i, a, b, s:longint;
BEGIN
  readln(n, m);
  
  for i:= 1 to n * m do
  begin
    read(a, b);
    
    if(a + b > 0) then s:= s + 1;
  end;
  
  writeln(s);
END.