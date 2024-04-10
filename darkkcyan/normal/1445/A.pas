uses math;
const maxn = 100;

var
    ntest: longint;
    n, x: longint;
    a, b: array[0..maxn] of longint;
    ans: boolean;
    i, t: longint;
    
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n, x);
        for i := 1 to n do read(a[i]);
        for i := 1 to n do read(b[i]);
        ans := true;
        while n > 0 do begin
            for i := 1 to n - 1 do begin
                if a[i] < a[n] then begin
                    t := a[i];
                    a[i] := a[n];
                    a[n] := t;
                end;
                if b[i] > b[n] then begin
                    t := b[i];
                    b[i] := b[n];
                    b[n] := t;
                end;
            end;
            if a[n] + b[n] > x then begin
                ans := false;
                break;
            end;
            dec(n);
        end;
        if ans then writeln('Yes')
        else writeln('No')
    end;
end.