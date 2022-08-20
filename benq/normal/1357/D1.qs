// This file is submitted by the participant
namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;
 
    // The operation that the participant has to implement
    // Has to return three things: 
    //  1) the feature engineering to perform (as an index in the array of feature engineering functions and an array of parameters to be used with it)
    //  2) circuit structure (as an array of ControlledRotation)
    //  3) and training results (circuit parameters + bias)
    //
    // The features engineering is built-in and cannot be tweaked by the participant's solution, only chosen from the list 
    // (see quantum-checker.qs for the list of available feature engineering functions)
    //
    
    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        let pre = (1,[0.5,0.5]);
        let rot = [
                    ControlledRotation((0, new Int[0]), PauliX, 4),
                    ControlledRotation((0, new Int[0]), PauliZ, 5),
                    ControlledRotation((1, new Int[0]), PauliX, 6),
                    ControlledRotation((1, new Int[0]), PauliZ, 7),
                    ControlledRotation((0, [1]), PauliX, 0),
                    ControlledRotation((1, [0]), PauliX, 1),
                    ControlledRotation((1, new Int[0]), PauliZ, 2),
                    ControlledRotation((1, new Int[0]), PauliX, 3)
                ];
        let param = [6.143478724693698,2.913096963360706,0.7565720526933304,1.0168992537291337,1.978718077881274,3.7376859642548883,-0.811512746398375,1.0273694723081879];
        let bias = -0.20671720692519527;
        return (pre,rot,(param,bias));
    }
 
 
 
}