var a: array[1..100] of longint;
   n,i,j,s,f,kol,kolf,ans: longint;
   Begin
    Read(n);
    kolf:=1000;
    For i:=1 to n do
      begin
        Read(a[i]);
        if a[i]=1 then inc(kol);
      end;
      For i:=1 to n do
         begin
         f:=0;
         s:=0;
          For j:=i to n do
             begin
              if a[j]=1 then inc(f)
              else inc(s);
              if s-f>=ans then ans:=s-f;
             end;
         end;
         if ans=0 then write(kol-1) else
         Write(kol+ans);
   End.