var s1,s2,s3: string;
    i,j,n,fn,sn: longint;
    used: boolean;
    Begin
        Readln(n);
        For i:=1 to n do
           Begin
             readln(s1);
             j:=1;
             While s1[j]<>' ' do
                 inc(j);
             inc(j);
             s2:='';
             s3:='';
             While s1[j] in ['0'..'9'] do
                 begin
                  s2:=s2+s1[j];
                  inc(j);
                 end;
             inc(j);
             While j<=length(s1) do
                 begin
                  s3:=s3+s1[j];
                  inc(j);
                 end;
                 val(s2,fn);
                 val(s3,sn);
                 if (fn>=2400) and (sn>fn) then used:=true;
           end;
           if used=true then writeln('YES')
           else Write('NO');
    End.