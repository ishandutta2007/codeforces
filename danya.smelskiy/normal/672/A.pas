var a,b: ansistring;
    i,j,n: longint;
      Begin
      Read(n);
        j:=1;
        While length(a)<n do
           begin
            str(j,b);
            a:=a+b;
            inc(j);
           end;
           Write(a[n]);
      End.