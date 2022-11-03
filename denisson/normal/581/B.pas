type mas=array [1..100007] of longint;
var  a:mas;
     i,n,max:longint;
begin
   read(n);
   for i:=1 to n do
      read(a[i]);
   max:=0;
   for i:=n downto 1 do
      begin
         if a[i]>max then begin
                             max:=a[i];
                             a[i]:=max-a[i];
                          end else if a[i]<=max then a[i]:=max-a[i]+1;
      end;
   for i:=1 to n do
      write(a[i],' ');
end.