const nnn = 1 shl 17;
var
    seg: array[0..nnn * 2 + 10] of longint;
    op: array[0..nnn * 2 + 10] of boolean;
    i, n, m, p, b: longint;

procedure update(i: longint);
begin
    if op[i] then seg[i] := seg[i shl 1] or seg[(i shl 1) or 1]
    else seg[i] := seg[i shl 1] xor seg[(i shl 1) or 1];
end;

begin
    readln(n, m);
    n := 1 shl n;
    fillchar(op, sizeof(op), 0);
    for i := 0 to n - 1 do read(seg[i + n]);
    for i := n - 1 downto 1 do begin
        op[i] := not op[i shl 1];
        update(i);
    end;

    while m > 0 do begin
        dec(m);
        readln(p, b); p := p - 1 + n;
        seg[p] := b;
        p := p shr 1;
        while p > 0 do begin
            update(p);
            p := p shr 1;
        end;
        writeln(seg[1]);
    end;
end.