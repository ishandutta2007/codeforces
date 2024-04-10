program task_2;

{$APPTYPE CONSOLE}

var ind1,mn,n,m,i,j,h:integer;
    t,c,r,l:array[1..100]of integer;
begin
  read(n,m);
  for i:=1 to m do read(l[i],r[i],t[i],c[i]);
  h:=0;
  for i:=1 to n do begin
    mn:=maxint;
    for j:=1 to m do
      if (i>=l[j])and(i<=r[j])and(t[j]<mn)then begin
        mn:=t[j];
        ind1:=j;
      end;
    if (mn<>maxint)then h:=h+c[ind1];
  end;
  write(h);
end.