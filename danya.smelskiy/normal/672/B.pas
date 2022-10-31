var a: ansistring;
    stroki: array['a'..'z'] of boolean;
    n,i,j,ans: longint;
    Begin
        ReadLn(n);
        ReadLn(a);
        if n>26 then
            begin
             Write('-1');
             Halt;
            end;
        for i:=1 to n do
            begin
             if stroki[a[i]]=false then
                 begin
                   stroki[a[i]]:=true;
                   for j:=i+1 to n do
                       if a[j]=a[i] then inc(ans);
                 end;
             if 26-ans<0 then
                 begin
                  Write('-1');
                  Halt;
                 end;
            end;
            if 26-ans>=0 then Write(ans)
            else Write('-1');
    End.