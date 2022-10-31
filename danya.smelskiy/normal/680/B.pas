uses math;
var a: array[-100..100] of longint;
     i,j,ans,k,b,c,n,m: longint;
     Begin
      Read(n,b);
      For i:=1 to n do Read(a[i]);
      if a[b]=1 then inc(ans);
      For i:=1 to max(n-b,b-1) do
         begin
           if (a[b-i]=1) and (a[b+i]=1) then inc(ans,2);
           if (b-i<=0) then if a[b+i]=1 then inc(ans);
           if (b+i>n) then if a[b-i]=1 then inc(ans);
         end;
         Write(ans);
     End.