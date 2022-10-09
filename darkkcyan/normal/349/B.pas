uses math;
var
v: longint;
a: array[1..9] of longint;
i, mi, maxlen: longint;
t: integer;
ans: ansistring;

begin
    readln(v);
    mi := 1 shl 30;
    for i := 1 to 9 do begin
        read(a[i]);
        mi := min(mi, a[i]);
    end;
    maxlen := v div mi;
    if maxlen = 0 then begin
        writeln(-1);
        halt;
    end;
    ans := '';
    for i := maxlen downto 1 do begin
        for t := 9 downto 1 do begin
            if (a[t] <= v) and ((v - a[t]) div mi = i - 1) then break;
        end;
        ans := ans + char(t + ord('0'));
        dec(v, a[t]);
    end;
    writeln(ans);
end.