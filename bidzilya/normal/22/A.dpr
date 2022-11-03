var
  a:array[-100..100]of integer;
  n,i,g,mn:integer;
  
begin
  read(n);
  for i:=-100 to 100 do
    a[i]:=0;
  mn:=maxint;
  for i:=1 to n do begin
    read(g);
    inc(a[g]);
    if g<mn then mn:=g;
  end;
  for i:=mn+1 to 100 do
    if a[i]>0 then begin write(i); halt; end;
  write('NO');
end.