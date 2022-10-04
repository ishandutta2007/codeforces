program C;

const mx = 300000;

var
i: integer;
n: integer;
a: array[0..mx - 1] of integer;
b: array[0..mx - 1] of integer;
cur_cnt, cnt: integer;

procedure update();
begin
            if (cnt = -1) then
            begin
                cnt := cur_cnt;
            end
            else
            begin
                if (cur_cnt <> cnt) then
                begin
                    writeln('NO');
                    halt(0);
                end;
            end;
            cur_cnt := 1;
end;

begin
    read(n);
    for i := 0 to n - 1 do
        read(a[i]);
    cnt := -1;
    cur_cnt := 0;
    for i := 0 to n - 1 do
    begin
        if ((i > 0) and (a[i] <> a[i - 1])) then
        begin
            update();
        end
        else
            inc(cur_cnt);
    end;
    update();
    writeln('YES');
end.