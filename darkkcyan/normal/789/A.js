"use strict";
if (typeof print == 'undefined') var print = console.log;
if (typeof readline == 'undefined') {
    let id = 0, lines = require('fs').readFileSync('/dev/stdin').toString().split('\n');
    var readline = () => lines[id ++];
}

let nums = () => readline().split(' ').map(x => +x);
let t = nums(), n = t[0], k = t[1];

let a = nums().map(x => Math.floor((x + k -1) / k)).reduce((m, n) => m + n, 0);
print(Math.floor((a + 1) / 2));