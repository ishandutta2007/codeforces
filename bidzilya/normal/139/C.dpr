{$APPTYPE CONSOLE}
const ds:array[1..4]of string=('aabb','abba','abab','aaaa');
var
  n,k,m,i,j,k1,k2,k3,k4:integer;
  a:array[1..10001]of string;
  b:array[1..6]of boolean;
  t:string;
begin
  readln(n,k);
  for i:=1 to n*4 do
  begin
    m:=0;
    readln(t);
    for j:=length(t)downto 1 do
    begin
      if (t[j] in ['a','e','i','o','u'])then
        inc(m);
      if (m=k)then
      begin
        a[i]:=copy(t,j,length(t)-j+1);
        break;
      end;
    end;
    if (m<k)then
    begin
      write('NO');
      halt;
    end;
  end;
  k1:=0;
  k2:=0;
  k3:=0;
  k4:=0;
  for i:=1 to n do
  begin
    b[1]:=a[(i-1)*4+1]=a[(i-1)*4+2];
    b[2]:=a[(i-1)*4+1]=a[(i-1)*4+3];
    b[3]:=a[(i-1)*4+1]=a[i*4];
    b[4]:=a[(i-1)*4+2]=a[(i-1)*4+3];
    b[5]:=a[(i-1)*4+2]=a[i*4];
    b[6]:=a[(i-1)*4+3]=a[i*4];
    if (b[1])and(b[6])then inc(k1);
    if (b[3])and(b[4])then inc(k2);
    if (b[2])and(b[5])then inc(k3);
    if (b[1])and(b[2])and(b[5])then inc(k4);
  end;
  if k4=n then writeln(ds[4])else
    if k1=n then writeln(ds[1])else
      if k2=n then writeln(ds[2])else
        if k3=n then writeln(ds[3])else
          writeln('NO');
end.