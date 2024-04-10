uses math;
const maxn = 20;

var
    n: longint;
    board: array [0..maxn] of string;

function count_crosses(r, c: longint; dr, dc: longint): longint;
begin
    if r < 1 then exit(0);
    if c < 1 then exit(0);
    if r >n then exit(0);
    if c > n then exit(0);
    if board[r][c] <> 'X' then exit(0);
    exit(count_crosses(r + dr, c + dc, dr, dc) + 1);
end;

procedure quit(msg: string = 'YES');
begin
    writeln(msg);
    halt;
end;

var i, f: longint;
begin
    n := 10;
    for i := 1 to n do readln(board[i]);
    for i := 1 to n do
    for f := 1 to n do begin
        if board[i][f] <> '.' then continue;
        if count_crosses(i - 1, f, -1, 0) + count_crosses(i + 1, f, 1, 0) >= 4 then quit();
        if count_crosses(i, f - 1, 0, -1) + count_crosses(i, f + 1, 0, 1) >= 4 then quit();
        if count_crosses(i - 1, f - 1, -1, -1) + count_crosses(i + 1, f + 1, 1, 1) >= 4 then quit();
        if count_crosses(i - 1, f + 1, -1, 1) + count_crosses(i + 1, f - 1, 1, -1) >= 4 then quit();
    end;
    writeln('NO');
end.