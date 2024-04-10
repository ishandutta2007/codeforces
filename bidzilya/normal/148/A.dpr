program A;

{$APPTYPE CONSOLE}
var i,d,n,m,k,l,ans: integer;
begin
  read(k,l,m,n,d);
  for i:=1 to d do
    if (i mod k=0)or(i mod l=0)or
       (i mod m=0)or(i mod n=0)then
        inc(ans);
  write(ans);
end.