var
s,s1,s2:string;
p:integer;
begin
  readln(s);
  p:=pos(' ',s);
  s1:=copy(s,1,p-1);
  s2:=copy(s,p+1,length(s)-p);
  if s1=s2 then write(s1) else write(1);
end.