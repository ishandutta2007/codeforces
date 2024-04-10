const
  map:array[1..9]of char=('6','7','8','9','T','J','Q','K','A');
var
  m1,m2,k,z1,z2:char;
  i1,i2,i:integer;
  s:string;
  
begin
  readln(k);
  readln(s);
  z1:=s[1];
  m1:=s[2];
  z2:=s[4];
  m2:=s[5];
  if m1=m2 then begin
    for i:=1 to 9 do
      if map[i]=z1 then begin i1:=i; break; end;
    for i:=1 to 9 do
      if map[i]=z2 then begin i2:=i; break; end;
    if i1>i2 then write('YES') else write('NO'); 
  end else 
    if m1=k then write('YES') else write('NO');  
  
end.