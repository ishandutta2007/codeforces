uses Math;
var
  n,m,j,k,mn,i,v1,v2:integer;
  a:array[1..100,1..100]of byte;
  c:array[1..100]of integer;

begin
  //assign(input,'input.txt');
  //reset(input);
  read(n,m);
  for i:=1 to n do
    read(c[i]);
  for i:=1 to m do begin
    read(v1,v2);
    a[v1,v2]:=1;
    a[v2,v1]:=1;
  end;
  mn:=maxint;
  for i:=1 to n do
    for j:=1 to n do
      if a[i,j]=1 then 
        for k:=j+1 to n do
          if (a[i,k]=1)and(a[j,k]=1)then 
            mn:=min(mn,c[i]+c[k]+c[j]);
  if mn=maxint then write('-1') else write(mn);
  //close(input);
end.