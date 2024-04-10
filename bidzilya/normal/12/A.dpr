var
  a:array[-1..1,-1..1]of char;
  s:String;
  i,j:integer;
  bol:boolean;
  
begin
  for i:=-1 to 1 do begin
    readln(s);
    for j:=-1 to 1 do
      a[i,j]:=s[j+2];
  end;
  bol:=true;
  for i:=-1 to 1 do
    for j:=-1 to 1 do
      if (a[i,j]='X')and(a[-i,-j]<>'X')then begin bol:=false; break; end;
  if bol then write('YES') else write('NO');
end.