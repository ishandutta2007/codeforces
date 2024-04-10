uses math;

var
    n, m: longint;
    a: array[0..10101] of longint;
    l, r, x: longint;
    i, g: longint;

begin
    read(n, m);
    for i := 1 to n do read(a[i]);
    while (m > 0) do begin
        dec(m);
        read(l, r, x);
        if (x < l) or (x > r) then begin
            writeln('Yes');
            continue;
        end;
        g := 0;
        for i := l to r do 
            if (a[i] < a[x]) then inc(g);
        if (g = x - l) then writeln('Yes')
        else writeln('No');
    end;
end.