var a: array[0..5] of int64;
    i,j,n,m,col,maxcol,sum,k,l,b,c: longint;
       Begin
        For i:=1 to 5 do
        begin
          Read(a[i]);
          sum:=sum+a[i];
        end;
        For i:=1 to 5 do
           begin
           col:=0;
            for j:=1 to 5 do
                  begin
                    if a[i]=a[j] then inc(col);
                    if col=3 then Break;
                    end;
               if (col*a[i]>maxcol) and (col in [2..3]) then
                   maxcol:=col*a[i];
           end;
        Write(sum-maxcol);
       End.