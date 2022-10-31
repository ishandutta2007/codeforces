var
  a,b:ansistring;
  i,diff,now,len:longint;
begin

  readln(a);
  readln(b);
  len:=length(a);
  diff:=0;
  for i:=1 to len do
    if a[i]<>b[i] then inc(diff);
  if diff mod 2=1 then writeln('impossible')
  else
  begin
    now:=0;
    for i:=1 to len do
      if a[i]=b[i] then write(a[i])
      else if now<diff div 2 then
      begin
        inc(now);
        write(a[i]);
      end
      else
        write(b[i]);
    writeln;

  end;
end.