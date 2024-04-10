var        i,n,m,ans: longint;
   Begin
    Read(n);
    For i:=1 to n do
       begin
        read(m);
        if (m=0) then inc(ans);
       end;
       if ((n=1) and (ans=0)) or ((n<>1) and (ans=1)) then write('YES')
       else Write('NO');
   End.