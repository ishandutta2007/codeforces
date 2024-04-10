var
n: integer;
a: array[1..101] of string;
i, f, g: integer;

const dr: array [1..4] of integer = (1, 1, 1, 2);
const dc: array [1..4] of integer = (0, -1, 1, 0);

function get(r, c: integer): char;
begin
    if (r > n) or (r < 1) or (c > n) or (c < 1) then exit('.');
    exit(a[r][c]);
end;

begin
{$ifndef ONLINE_JUDGE}
    assign(input, 'in.txt');    reset(input);
    assign(output, 'out.txt');  rewrite(output);
{$endif}
    readln(n);
    for i := 1 to n do readln(a[i]);
    for i := 1 to n do begin
        for f := 1 to n do begin
            if get(i, f) = '.' then continue;
            for g := 1 to 4 do begin
                if (get(i + dr[g], f + dc[g]) = '.') then begin
                    writeln('NO');
                    halt;
                end;
            end;
            for g := 1 to 4 do
                a[i + dr[g], f + dc[g]] := '.';
        end;
    end;
    writeln('YES');
end.