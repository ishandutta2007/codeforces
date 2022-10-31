var
  v:array['A'..'Z']of boolean;
  c:char;
  n,i:longint;
  flag:boolean;
begin

  readln(n);
  fillchar(v,sizeof(v),false);
  for i:=1 to n do
  begin
    read(c);
    v[upcase(c)]:=true;
  end;
  flag:=true;
  for c:='A'to'Z'do
    if not v[c] then flag:=false;
  if flag then writeln('YES') else writeln('NO');

end.