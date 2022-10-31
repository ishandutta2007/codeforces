var i,j,n,k,ans: longint;
    Begin
     Read(n,i);
     For j:=1 to n do
        begin
         Read(k);
         if k>i then inc(ans,2)
         else inc(ans);
        end;
        Write(ans);
    End.