var
  a,b:array[0..500]of int64;
  w:Array[0..500,0..500]of int64;
  c,inf:int64;
  i,j,n,m:longint;
  flag:boolean;
function gcd(x,y:int64):int64;
begin
  if y=0 then exit(x);
  exit(gcd(y,x mod y));
end;
begin

  read(n,m);
  for i:=0 to n-1 do
    for j:=0 to m-1 do
      read(w[i,j]);
  for i:=0 to m-1 do b[i]:=w[0,i];
  for i:=1 to n-1 do a[i]:=w[i,0]-b[0];
  inf:=0;
  for i:=0 to n-1 do
    for j:=0 to m-1 do
    begin
      c:=abs(a[i]+b[j]-w[i,j]);
      inf:=gcd(inf,c);
    end;
  if inf=0 then inf:=10000000007;
  flag:=true;
  for i:=0 to n-1 do
    for j:=0 to m-1 do
      if w[i,j]>=inf then flag:=false;
  if not flag then writeln('NO')
  else
  begin
    writeln('YES');
    writeln(inf);
    for i:=0 to n-1 do write((a[i]+inf)mod inf,' ');
    writeln;
    for i:=0 to m-1 do write((b[i]+inf)mod inf,' ');
  end;
  close(input);
  close(output);
end.