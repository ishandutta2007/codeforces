var n,ans: longint;
   Begin
    Read(n);
    ans:=n div 2;
    if n mod 2=1 then inc(ans);
    Write(ans);
   End.