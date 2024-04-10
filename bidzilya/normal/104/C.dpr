var
  a:array[1..100,1..100]of integer;
  b:array[1..100]of boolean;
  i,v1,v2,m,n:integer;
  
procedure dfs(v:integer);
var i:integer;
begin
  b[v]:=true;
  for i:=1 to n do
    if (a[v,i]=1)and(not b[i]) then dfs(i);
end;
  
begin
  //assign(input,'input.txt');
  //reset(input);
  read(n,m);
  for i:=1 to m do begin
    read(v1,v2);
    a[v2,v1]:=1;
    a[v1,v2]:=1;
  end;
  for i:=1 to n do
    b[i]:=false;
  dfs(1);
  for i:=1 to n do
    if not b[i] then begin write('NO'); halt; end;
  if m=n then begin
    write('FHTAGN!');
    halt;
  end;
  write('NO');
end.