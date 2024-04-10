uses math;
const maxn = 10101;

var
    ntest: longint;
    n: longint;
    s: ansistring;
    cnt: array[0..3] of longint;
    i: longint;
    
begin
    readln(ntest);
    while (ntest > 0) do begin
        dec(ntest);
        readln(s);
        n := length(s);
        for i := 0 to 3 do cnt[i] := 0;
        for i := 1 to n do begin
            inc(cnt[ord(s[i]) - ord('A')]);
        end;
        
        if cnt[0] + cnt[2] = cnt[1] then writeln('YES')
        else writeln('NO');
    end;
end.