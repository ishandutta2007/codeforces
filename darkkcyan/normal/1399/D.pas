uses math;
const maxn = 201010;
const op: array['0'..'1'] of char = ('1', '0');

var
    ntest: longint;
    n: longint;
    s: ansistring;
    i: longint;
    st: array['0'..'1', 0..maxn] of longint;
    sz: array['0'..'1'] of longint;
    group: array[0..maxn] of longint;
    ans: longint;
    ch: char;
    
begin
    readln(ntest);
    for ntest := 1 to ntest do begin
        readln(n);
        readln(s);
        ans := 0;
        sz['0'] := 0;
        sz['1'] := 0;
        
        for i := 1 to n do begin
            ch := op[s[i]];
            if sz[ch] = 0 then begin
                inc(ans);
                group[i] := ans;
            end else begin
                dec(sz[ch]);
                group[i] := st[ch][sz[ch]];
            end;
            st[s[i]][sz[s[i]]] := group[i];
            inc(sz[s[i]]);
        end;
        writeln(ans);
        for i := 1 to n do write(group[i], ' ');
        writeln;
    end;
end.