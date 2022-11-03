var
  s1,s2:string;
  c:char;
  l,i:integer;
  bol:boolean;
begin
  readln(s1);
  readln(s2);
  bol:=true;
  l:=length(s1);
  if l<>length(s2) then bol:=false;
  if bol then
  for i:=l downto 1 do
    if s1[i]<>s2[l-i+1] then begin bol:=false; break; end;
  if bol then write('YES') else write('NO');
end.