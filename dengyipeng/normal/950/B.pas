var
        n,m,i,j,ans,s1,s2:longint;
        a,b:array[1..1000005] of longint;
begin
        readln(n,m);
        for i:=1 to n do read(a[i]);
        for i:=1 to m do read(b[i]);
        i:=0; j:=0; s1:=0; s2:=0;
        repeat
                if s1<=s2 then begin inc(i);inc(s1,a[i]); end else
                begin inc(j);inc(s2,b[j]); end;
                if s1=s2 then inc(ans);
        until (i=n)and(j=m);
        writeln(ans);
end.