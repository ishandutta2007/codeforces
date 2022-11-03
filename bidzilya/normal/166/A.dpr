program Task1;

{$APPTYPE CONSOLE}

var
  z,t: array[1..50]of integer;
  n,k,buf,i,j: integer;
begin
  read(n,k);
  for i:=1 to n do
    read(z[i], t[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (z[j]>z[i])or((z[j]=z[i])and(t[j]<t[i]))then begin
        buf:=z[i];z[i]:=z[j];z[j]:=buf;
        buf:=t[i];t[i]:=t[j];t[j]:=buf;
      end;
  i:=k;j:=k;
  while (i>1)and(z[i-1]=z[i])and(t[i-1]=t[i])do dec(i);
  while (j<n)and(z[j+1]=z[j])and(t[j+1]=t[j])do inc(j);
  writeln(j-i+1);
end.