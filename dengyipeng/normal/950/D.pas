var
        n,q,x,i:int64;
begin
        readln(n,q);
        while q>0 do
        begin
                dec(q);
                readln(x);
                i:=n-(x+1) div 2;
                while x mod 2=0 do
                begin
                        x:=x+i;
                        i:=i div 2;
                end;
                writeln((x+1) div 2);
        end;
end.