uses math;
var
    s, v1, t1, v2, t2: longint;
begin
    read(s, v1, v2, t1, t2);
    inc(t1, s * v1 + t1);
    inc(t2, s * v2 + t2);
    if t1 < t2 then writeln('First')
    else if t1 > t2 then writeln('Second')
    else writeln('Friendship');
end.