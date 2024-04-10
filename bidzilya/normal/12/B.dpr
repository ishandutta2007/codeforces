var
  san,s1,s2:string;
  i,j,ind:integer;
  mn:char;
  
begin
  readln(s1);
  readln(s2);
  mn:=chr(255);
  ind:=-1;
  san:='';
  for i:=1 to length(s1) do 
    if (s1[i]<mn)and(s1[i]<>'0') then begin mn:=s1[i]; ind:=i; end;
  if ind<>-1 then delete(s1,ind,1);
  if (mn>='0')and(mn<='9') then san:=san+mn;
  for i:=1 to length(s1)-1 do
    for j:=i+1 to length(s1) do
      if s1[j]<s1[i] then begin mn:=s1[i]; s1[i]:=s1[j]; s1[j]:=mn; end;
  san:=san+s1;
  if san=s2 then write('OK') else write('WRONG_ANSWER');
end.