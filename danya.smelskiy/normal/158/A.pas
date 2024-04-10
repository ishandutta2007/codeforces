var ans,n,m,i: longint;
  a: array[1..50] of longint;
    Begin
      Read(n,m);
      For i:=1 to n do
       Read(a[i]);
      For i:=1 to n do
         if (a[i]>=a[m])and(a[i]>0) then inc(ans);
         Write(ans);
    End.