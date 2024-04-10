var
        s:ansistring;
        n,i,j,k,t,w,ans:longint;
        d,next:array[1..200000] of longint;
        bz:array[1..200000] of boolean;
begin
        readln(s);
        n:=length(s);
        t:=0; w:=0;
        for i:=1 to n do
        begin
                if s[i]='0' then begin inc(w); d[w]:=i; end else
                begin
                        if t=w then begin writeln(-1); halt; end;
                        inc(t); next[d[t]]:=i; bz[i]:=true;
                end;
        end;
        t:=0; w:=0;
        for i:=n downto 1 do
        begin
                if s[i]='0' then begin inc(w); d[w]:=i; end else
                begin
                        if t=w then begin writeln(-1); halt; end;
                        inc(t); next[i]:=d[t]; bz[d[t]]:=true;
                end;
        end;
        ans:=0;
        for i:=1 to n do if bz[i]=false then inc(ans);
        writeln(ans);
        for i:=1 to n do if bz[i]=false then
        begin
                j:=i; k:=1; while next[j]<>0 do begin j:=next[j]; inc(k); end;
                write(k,' ',i,' ');
                j:=i; while next[j]<>0 do begin j:=next[j]; write(j,' '); end;
                writeln;
        end;

end.