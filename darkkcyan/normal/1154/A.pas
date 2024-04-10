var
    a: array[0..3] of int64;
    i, max_i: longint;

begin
    for i := 0 to 3 do read(a[i]);
    max_i := 0;
    for i := 1 to 3 do
        if a[max_i] < a[i] then max_i := i;
    
    for i := 1 to 3 do
        write(a[max_i] - a[(max_i + i) mod 4], ' ');
end.