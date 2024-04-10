{$mode objfpc}
uses sysutils, math;

var n: longint;
var i: longint;
var line: ansistring;
var cur_name: ansistring;
var point_added: longint;

const maxn = 1111;
type ds = record
    name: ansistring;
    point: longint;
    canwin: boolean;
end;
type pds = ^ds;
var a: array[0..maxn] of ds;
var cnt: longint = 0;

function find(name: ansistring): pds;
var i: longint;
begin
    for i := 1 to cnt do
        if a[i].name = name then exit(@a[i]);
    inc(cnt);
    a[cnt].name := name;
    a[cnt].point := 0;
    a[cnt].canwin := false;
    exit(@a[cnt]);
end;

type history_point = record
    who: pds;
    cur_point: longint;
end;
var history: array[0..maxn] of history_point;
var max_score: longint = 0;
begin
    readln(n);
    for i := 1 to n do begin
        readln(line);
        sscanf(line, '%s %d', [@cur_name, @point_added]);
        history[i].who := find(cur_name);
        inc(history[i].who^.point, point_added);
        history[i].cur_point := history[i].who^.point;
    end;
    for i := 1 to cnt do begin
        max_score := max(max_score, a[i].point);
    end;
    for i := 1 to cnt do begin
        if a[i].point = max_score then a[i].canwin := true;
    end;
    for i := 1 to n do begin
        if not history[i].who^.canwin then continue;
        if history[i].cur_point < max_score then continue;
        writeln(history[i].who^.name);
        break;
    end;
end.