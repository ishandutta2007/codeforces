"use strict"
if (typeof print === 'undefined') var print = console.log;
if (typeof readline === 'undefined') {
    let lines = require('fs').readFileSync('/dev/stdin').toString().split('\n'), id = 0;
    var readline = () => lines[id++];
}

var x = +readline();
var a = readline().split(' ').map(x => +x).sort((a, b) => a - b);

var ans = Infinity;
var cnt = 0;

for (var i = 0; ++i < x; ) {
    var diff = a[i] - a[i - 1];
    //console.warn(diff);
    if (diff > ans) continue;
    if (diff < ans) {
        ans = diff;
        cnt = 0;
    }
    if (diff == ans) ++cnt;
}

print(ans + ' ' + cnt);