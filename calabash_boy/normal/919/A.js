'use strict';
var inputData = readline().split(' ');
var n = parseInt(inputData[0]);
var m = parseInt(inputData[1]);
var cost = [];
for (var i = 0; i < n; i++) {
    var input = readline().split(' ');
    var a = parseInt(input[0]);
    var b = parseInt(input[1]);
    cost.push(a / b);
}
print(Math.min.apply(Math, cost) * m);