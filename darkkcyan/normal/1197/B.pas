{$mode objfpc}
const maxn = 201010;
var
    n: longint;
    a: array[0..maxn] of longint;
    i: longint;
    max_pos: longint;

procedure no();
begin writeln('No'); halt(0); end;

begin
    read(n);
    for i := 1 to n do read(a[i]);
    max_pos := 1;
    for i := 2 to n do 
        if (a[i] > a[max_pos]) then max_pos := i;

    for i := max_pos downto 2 do
        if a[i] < a[i - 1] then no();
    
    for i := max_pos to n - 1 do 
        if a[i] < a[i + 1] then no();

    writeln('Yes');
end.