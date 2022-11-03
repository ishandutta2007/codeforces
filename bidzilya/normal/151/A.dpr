program tasK_a;

{$APPTYPE CONSOLE}
uses Math;
var nl,np,p,k,c,n,l,d,ans: integer;
begin
  read(n,k,l,c,d,p,nl,np);
  k:=k*l div nl;
  c:=c*d;
  p:=p div np;
  write(min(min(p,c),k)div n);
end.