var
  m,i,j,k,v1,v2:integer;
  a:array[1..5,1..5]of integer;
  str:string;
  
function prove(l,b,c:integer):boolean;
begin
  result:=false;
  if (a[l,b]=1)and(a[l,c]=1)and(a[b,c]=1)then result:=true;
  if (a[l,b]=0)and(a[l,c]=0)and(a[b,c]=0)then result:=true;
end;

begin
  for i:=1 to 5 do
    for j:=1 to 5 do
      a[i,j]:=0;
  read(m);
  for i:=1 to m do begin
    read(v1,v2);
    a[v1,v2]:=1;
    a[v2,v1]:=1;
  end;
  str:='FAIL';
  for i:=1 to 3 do 
    for j:=i+1 to 4 do
      for k:=j+1 to 5 do
        if prove(i,j,k) then begin str:='WIN'; writeln(str); halt; end; 
  writeln(str);
end.