let inputs = []

function read() {
    return inputs.pop();
}

function readInt() {
    return parseInt(read());
}

function solve() {
    let test = readInt();
    while (test--) {
        let k = readInt();
        let c = parseInt(Math.sqrt(k - 1)) + 1;
        while (k - 1 < c * c) c--;
        let r = k - c * c;
        if (r <= c) {
            console.log(r + ' ' + (c + 1));
        }
        else {
            console.log((c + 1) + ' ' + (2 * c - r + 2));
        }
    }
}

function main() {
    inputs = inputString.trim().split(/\n| /).map((string) => string.trim());
    inputs.reverse(); 
    solve();
}

let inputString = '';

process.stdin.on('data', (inputStdin) => { inputString += inputStdin; });

process.stdin.on('end', (_) => { main(); });