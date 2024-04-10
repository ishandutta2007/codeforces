var n,m,i,j,k: longint;
     ans: int64;
    Begin
     Read(n,m);
     For i:=1 to n do
        begin
         j:=1;
         While ((i+j) mod 5<>0) and (j<=m) do
            inc(j);
         if ((i+j) mod 5=0) and (j<=m) then
             begin
             inc(ans);
              ans:=ans+((m-j) div 5);
             end;
        end;
        Write(ans);
    End.