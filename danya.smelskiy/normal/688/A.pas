var online: array[-10..1000] of boolean;
    i,j,n,m,last,max: longint;
    z: boolean;
    k: char;
    Begin
       ReadLn(n,m);
       For i:=1 to m do
          begin
            z:=false;
             For j:=1 to n do
                 begin
                   read(k);
                   if k='0' then z:=true;
                 end;
             Readln;
             if z=true then online[i]:=true;
             if (online[i-1]=true) and (online[i]=true) then inc(last)
             else
                begin
                   if last>max then max:=last;
                   if online[i]=true then last:=1;
                end;
          end;
          if last>max then max:=last;
          Writeln(max);
    End.